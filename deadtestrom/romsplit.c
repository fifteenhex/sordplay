#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define ROMSIZE (8 * 1024)

static uint8_t input[ROMSIZE * 2];
static uint8_t output_even[ROMSIZE];
static uint8_t output_odd[ROMSIZE];

int main (int argc, char **argv)
{
	const char *input_path;
	const char *output_prefix;
	char output_path_even[1024];
	char output_path_odd[1024];
	int fd_input, fd_output_even, fd_output_odd;
	int ret;
	int i;

	if (argc != 3) {
		printf("Usage: %s <input> <output prefix\n", argv[0]);
		return 1;
	}

	input_path = argv[1];
	fd_input = open(input_path, O_RDONLY);
    	if (fd_input < 0) {
		printf("Failed to open %s\n", input_path);
		return 1;
	}

	output_prefix = argv[2];
	sprintf(output_path_even, "%s.even", output_prefix);
	sprintf(output_path_odd, "%s.odd", output_prefix);


	fd_output_even = open(output_path_even, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (fd_output_even < 0) {
		printf("Failed to create %s\n", fd_output_even);
		return 1;
	}

	fd_output_odd = open(output_path_odd, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (fd_output_odd < 0) {
		printf("Failed to create %s\n", fd_output_odd);
		return 1;
	}

	memset(input, 0xff, sizeof(input));

	read(fd_input, input, sizeof(input));

	for (i = 0; i < sizeof(input); i += 2) {
		output_even[i >> 1] = input[i];
		output_odd[i >> 1] = input[i + 1];
	}

	ret = write(fd_output_even, output_even, sizeof(output_even));
	if (ret != sizeof(output_even)) {
		printf("Failed to write even: %d\n", ret);
		return 1;
	}

	ret = write(fd_output_odd, output_odd, sizeof(output_odd));
	if (ret != sizeof(output_odd)) {
		printf("Failed to write odd\n");
		return 1;
	}

	return 0;
}
