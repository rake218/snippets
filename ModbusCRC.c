/*!
 * Function : UI8_CRC
 * @brief This function calculates the CRC code 16 bits for the entered
 *        buffer and size.
 *
 * @param   a_ui8NAr_Buffer:   The Array of data on which CRC has to be performed
 * @param   a_ui8N_BufferSize: The size of the Input Array buffer.
 * @return  The CRC value ( in 16 bits )
 *
 * \b Example Example:
 * @code
 *
 * uint16_t CRC = UI8_CRC( uint8_t a_ui8NAr_Buffer[ ], uint8_t a_ui8N_BufferSize );
 *
 * @endcode
 *
 *
 * @warning Make sure the size of a_ui8NAr_Buffer[ ] and the a_ui8N_BufferSize
 *          matches.
 *
 * @see http://irtfweb.ifa.hawaii.edu/~smokey/software/about/sixnet/modbus/modbus_protocol.pdf
 */
uint16_t UI8_CRC( uint8_t a_ui8NAr_Buffer[ ], uint8_t a_ui8N_BufferSize )
{
    uint8_t a_ui8N_loopCnt1, a_ui8N_loopCnt2;

    uint16_t a_ui16N_CRC = 0xFFFF;

    for ( a_ui8N_loopCnt1 = 0; a_ui8N_loopCnt1 < a_ui8N_BufferSize;
            a_ui8N_loopCnt1++ )
    {

        a_ui16N_CRC ^= a_ui8NAr_Buffer[ a_ui8N_loopCnt1 ];

        for ( a_ui8N_loopCnt2 = 0; a_ui8N_loopCnt2 < 8; a_ui8N_loopCnt2++ )
        {
            if ( ( a_ui16N_CRC & 0x01 ) != 0 )
            {
                a_ui16N_CRC = ( a_ui16N_CRC >> 1 ) ^ 0xA001;
            }
            else
            {
                a_ui16N_CRC = ( a_ui16N_CRC >> 1 );
            }
        }
    }
    return ( a_ui16N_CRC );
}
