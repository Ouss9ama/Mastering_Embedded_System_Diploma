/* startup_cortex_m3
Oussama Sahraoui
*/


/* SRAM start at 0x20000000 */
.section .vectors         /* . section a command that make the assembler put the below instru in a section called vector */

.word 0x20001000
.word _reset
.word Vector_handler /* should be 2 NMI */
.word Vector_handler /* Should be 3 Hard Fault but to simplify we used Vector_handler */
.word Vector_handler /* should be 4 MM fault */
.word Vector_handler /* should be 5 Bus Fault */
.word Vector_handler /* should be 6 Usage Fault */
.word Vector_handler /* should be 7 RESERVED */
.word Vector_handler /* should be 8 RESERVED */
.word Vector_handler /* should be 9 RESERVED */
.word Vector_handler /* should be 10 RESERVED */
.word Vector_handler /* should be 11 SV call */
.word Vector_handler /* should be 12 Debug Reserved */
.word Vector_handler /* should be 13 Reserved */
.word Vector_handler /* should be 14 PendSV */
.word Vector_handler /* should be 15 SysTick */
.word Vector_handler /* should be 16 IRQ0 */
.word Vector_handler /* should be 17 IRQ1 */
.word Vector_handler /* should be 18 IRQ2 */
.word Vector_handler /* ...... */

.section .text
_reset:
	bl main
	b .
.thumb_func 
Vector_handler:
	b _reset

 