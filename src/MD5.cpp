//
//  MD5.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 11/2/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "MD5.h"
#include <CommonCrypto/CommonDigest.h>

namespace ccHelp
{
    std::string md5(const char *data, ssize_t len)
    {
        // Create byte array of unsigned chars
        static unsigned char md5Buffer[CC_MD5_DIGEST_LENGTH];
        
        // Create 16 byte MD5 hash value, store in buffer
        CC_MD5(data, len, md5Buffer);
        
        std::stringstream ss;
        for(int i = 0; i < CC_MD5_DIGEST_LENGTH; i++)
            ss<<cocos2d::StringUtils::format("%02x", md5Buffer[i]);
        
        return ss.str();
    }
}