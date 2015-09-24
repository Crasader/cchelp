
//
//  BINARY.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 9/24/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

template< unsigned long long N >
struct bin
{
    enum { value = (N % 8) + 2 * bin< N / 8 > :: value } ;
};

template<>
struct bin< 0 >
{
    enum { value = 0 } ;
};
