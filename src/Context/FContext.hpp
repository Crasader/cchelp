//
//  FContext.h
//  ccHelp_ios_mac
//
//  Created by Vinova on 6/26/15.
//  Copyright (c) 2015 Less. All rights reserved.
//

#pragma once

namespace ccHelp
{
    template <>
    bool FContext::get<char>(const std::string &k, char &v) const;
    template <>
    bool FContext::get<unsigned char>(const std::string &k, unsigned char &v) const;
    
    template <>
    bool FContext::get<short>(const std::string &k, short &v) const;
    template <>
    bool FContext::get<unsigned short>(const std::string &k, unsigned short &v) const;
    
    template <>
    bool FContext::get<int>(const std::string &k, int &v) const;
    template <>
    bool FContext::get<unsigned int>(const std::string &k, unsigned int &v) const;
    
    template <>
    bool FContext::get<long>(const std::string &k, long &v) const;
    template <>
    bool FContext::get<unsigned long>(const std::string &k, unsigned long &v) const;
    
    template <>
    bool FContext::get<float>(const std::string &k, float &v) const;
    template <>
    bool FContext::get<double>(const std::string &k, double &v) const;
    
    template <>
    bool FContext::get<bool>(const std::string &k, bool &v) const;
    
    template <>
    bool FContext::get<std::string>(const std::string &k, std::string &v) const;
}