

#ifndef HMAC_H
#define HMAC_H

void hmac_sha1(uint8_t * key, int32_t key_length,
               const uint8_t* data, uint32_t data_length,
               uint8_t* mac, int32_t* mac_length );

void hmac_sha1( uint8_t* key, int32_t key_length,
                const uint8_t* data_chunks[],
                uint32_t data_chunck_length[],
                uint8_t* mac, int32_t* mac_length ) ;

#endif
