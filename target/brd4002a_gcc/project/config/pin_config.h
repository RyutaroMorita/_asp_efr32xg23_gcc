#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// GPIO SWV on PA03
#ifndef GPIO_SWV_PORT                           
#define GPIO_SWV_PORT                            gpioPortA
#endif
#ifndef GPIO_SWV_PIN                            
#define GPIO_SWV_PIN                             3
#endif

// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// USART0 CTS on PA10
#ifndef USART0_CTS_PORT                         
#define USART0_CTS_PORT                          gpioPortA
#endif
#ifndef USART0_CTS_PIN                          
#define USART0_CTS_PIN                           10
#endif

// USART0 RTS on PA00
#ifndef USART0_RTS_PORT                         
#define USART0_RTS_PORT                          gpioPortA
#endif
#ifndef USART0_RTS_PIN                          
#define USART0_RTS_PIN                           0
#endif

// USART0 RX on PA09
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortA
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            9
#endif

// USART0 TX on PA08
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortA
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            8
#endif

// [USART0]$

// $[I2C1]
// [I2C1]$

// $[EUSART1]
// [EUSART1]$

// $[EUSART2]
// [EUSART2]$

// $[LCD]
// [LCD]$

// $[KEYSCAN]
// [KEYSCAN]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[VDAC0]
// [VDAC0]$

// $[PCNT0]
// [PCNT0]$

// $[LESENSE]
// [LESENSE]$

// $[HFXO0]
// [HFXO0]$

// $[I2C0]
// [I2C0]$

// $[EUSART0]
// [EUSART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef VCOM_RTS_PORT                           
#define VCOM_RTS_PORT                            gpioPortA
#endif
#ifndef VCOM_RTS_PIN                            
#define VCOM_RTS_PIN                             0
#endif

#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     1
#endif

#ifndef VCOM_TX_PORT                            
#define VCOM_TX_PORT                             gpioPortA
#endif
#ifndef VCOM_TX_PIN                             
#define VCOM_TX_PIN                              8
#endif

#ifndef VCOM_RX_PORT                            
#define VCOM_RX_PORT                             gpioPortA
#endif
#ifndef VCOM_RX_PIN                             
#define VCOM_RX_PIN                              9
#endif

#ifndef VCOM_CTS_PORT                           
#define VCOM_CTS_PORT                            gpioPortA
#endif
#ifndef VCOM_CTS_PIN                            
#define VCOM_CTS_PIN                             10
#endif

#ifndef VCOM_ENABLE_PORT                        
#define VCOM_ENABLE_PORT                         gpioPortB
#endif
#ifndef VCOM_ENABLE_PIN                         
#define VCOM_ENABLE_PIN                          0
#endif

#ifndef UIF_PB0_PORT                            
#define UIF_PB0_PORT                             gpioPortB
#endif
#ifndef UIF_PB0_PIN                             
#define UIF_PB0_PIN                              1
#endif

#ifndef UIF_LED0_PORT                           
#define UIF_LED0_PORT                            gpioPortB
#endif
#ifndef UIF_LED0_PIN                            
#define UIF_LED0_PIN                             2
#endif

#ifndef UIF_PB1_PORT                            
#define UIF_PB1_PORT                             gpioPortB
#endif
#ifndef UIF_PB1_PIN                             
#define UIF_PB1_PIN                              3
#endif

#ifndef UIF_LED1_PORT                           
#define UIF_LED1_PORT                            gpioPortD
#endif
#ifndef UIF_LED1_PIN                            
#define UIF_LED1_PIN                             3
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

