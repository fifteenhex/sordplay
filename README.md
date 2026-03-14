# MX-MAIN-C

The markings on some of the chips on this board are barely visible. Some totally missing.

|   | 1           | 2                       | 3           | 4           | 5           | 6              | 7                       | 8        | 9                      | 10                | 11 |   |
|---|-------------|-------------------------|-------------|-------------|-------------|----------------|-------------------------|----------|------------------------|-------------------|----|---|
| t |     *       | *                       | *           | SN74LS245N  |             |                |                         |          |                        | MB83256 (019 RA)  |  * | v |
| s | mc68000     | *                       | *           | SN74LS245N  |             |                |                         |          |                        | MB83256 (020 RA)  |  * | u |
| r | HD74LS245WP | HD74LS245WP             | SN74LS245N  | SN74LS373N  |             |                |                         |          |                        |        *          |  * | t |
| p | SN74LS670N  | SN74LS670N              | HD74LS245WP | HD74LS245WP |             |                |                         |          |                        | MB83256 (021 RA)  |  * | s |
| n |             | SN7417N                 | ?8257c-2    | *           |             |                |                         |          |                        | (serial sticker)  |  * | r |
|   |             |                         |             |             |             |                |                         |          |                        |        *          |  * | p |
|   |             |                         |             |             |             |                |                         |          |                        | MB83256 (022 RA)  |  * | n |
|   |             |                         |             |             |             |                |                         |          |                        |        *          |  * | m |
|   |             |                         |             |             |             |                |                         |          |                        | MB83256 (027 RA)  |  * | l |
| k |             | SN74LS04N               | 20mhz xtal  | SN74LS04N   |             |                |                         |          |                        | MB83256 (028 RA)  |  * | k |
| j | HD74LS244P  |                         |             |             |             |                |                         |          | 26.667mhz xtal         | MB83256 (029 RA)  |  * | j |
| h | SN74LS259N  | MC6840P                 |             |             |             |                |                         |          | SN74LS646NT            | MB83256 (030 RA)  |  * | h |
| g | SN74LS123N  |                         |             |             |             |                |                         |          | MB8416A-15L-SK (EKL 1) |                   |    | g |
| f | SN75452BP   | MBM2764-20 (?even? ROM) |             | MB8416A-15L | SN74LS646NT | SN74LS08N      | GA041 (NEC gate array?) | *        | MB8416A-15L-SK (EKR 1) | D2764D (M68MX CG) |  * | f |
| e | 16mhz xtal  | MBM2764-20 (ODD ROM)    |             | MB8416A-15L | SN74LS646NT |                |                         |          | MB8416A-15L-SK (EKL 0) | SN74LS138N        |    | e |
| d | relay?      |                         | SN74LS157N  | MB8416A-15L | SN74LS646NT |                | PL042                   | PL084    | MB8416A-15L-SK (EKR 0) | SN74LS138N        |    | d |
| c | SED9421     |                         |             | SN74LS245N  | SN74LS245N  | SN74LS86N      | 74F194PC                | 74F194PC |                        | SN7416N           |    | c |
| b | SN7416N     | ?NEC FDC?               | *           | SN7416N     | SN74LS373N  | SN74LS123N     | HD6850P (ACIA KB)       | 74F194PC |                        |                   |    | b |
| a | SN74LS00N   | CK2605 - PL085          | SN7416N     | SN74LS14N   |             | resistor packs |                         |          |                        |                   |    | a |
|   |  1          | 2                       | 3           | 4           | 5           | 6              | 7                       | 8        | 9                      | 10                | 10 |   |


mc68000 reset -> 4 + 11 of n2

reset sw -> a1 -> 4b -> r32+r33

MB83256 roms are Kanji roms -> https://haserin09.la.coocan.jp/kanji_rom.html
