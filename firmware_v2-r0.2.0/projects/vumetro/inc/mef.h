#ifndef _MEF_H_
#define _MEF_H_

/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
typedef enum {BAND1, BAND2, BAND3, BAND4, BAND5, BAND6, BAND7, BAND8, ALL}state;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
void MEF_init();

void MEF_update();

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _MEF_H_ */
