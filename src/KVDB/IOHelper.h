//
//  IOHelper.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 7/3/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once
#include "Def.h"

namespace ccHelp
{
    class IOHelper
    {
    private:
        std::deque<uint> stCursors;
        FILE *f;
        
    public:
        IOHelper();
        
        bool open(const char *path, const char *mode);
        void close();
        
        uint tell();
        void flush();
        
        
        template<typename T>
        T read()
        {
            T t;
            fread(&t, sizeof(T), 1, f);
            return t;
        }
        
        template <typename T>
        T peek()
        {
            T t = read<T>();
            seek(-sizeof(T), SEEK_CUR);
            return t;
        }
        
        template<typename T>
        void write(const T &t)
        {
            fwrite(&t, sizeof(T), 1, f);
        }
        
        void read(char *buffer, uint len);
        void write(const char *buffer, uint len);
        
        void seek(int seek, int mode = SEEK_SET);
        void seekAndPush(uint seek);
        void backAndPop();
    };
}
