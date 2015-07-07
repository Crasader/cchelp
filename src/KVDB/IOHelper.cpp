//
//  IOHelper.cpp
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/3/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#include "IOHelper.h"

namespace ccHelp {
    IOHelper::IOHelper()
    : f(nullptr)
    {
        
    }
    
    bool IOHelper::open(const char *path, const char *mode)
    {
        assert(!f);
        f = fopen(path, mode);
        
        if (f)
        {
            fseek(f, 0, SEEK_SET);
        }
        
        return (f != nullptr);
    }
    
    void IOHelper::close()
    {
        if (f)
        {
            fclose(f);
            f = nullptr;
        }
    }
    
    uint IOHelper::tell()
    {
        return (uint) ftell(f);
    }
    
    void IOHelper::flush()
    {
        fflush(f);
    }
    
    void IOHelper::read(char *buffer, uint len)
    {
        fread(buffer, sizeof(char), len, f);
    }
    
    void IOHelper::write(const char *buffer, uint len)
    {
        fwrite(buffer, sizeof(char), len, f);
    }
    
    void IOHelper::seek(uint seek, int mode)
    {
        fseek(f, seek, mode);
    }
    
    void IOHelper::seekAndPush(uint seek)
    {
        stCursors.push_back((uint) ftell(f));
        fseek(f, seek, SEEK_SET);
    }
    
    void IOHelper::backAndPop()
    {
        if (stCursors.empty())
        {
            uint seek = stCursors.back();
            stCursors.pop_back();
            
            fseek(f, seek, SEEK_SET);
        }
    }
}