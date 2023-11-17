#include <fuzzer/FuzzedDataProvider.h>
#include <string>
#include <iostream>
#include <stdio.h>

#include "miniscript_policy.h"
#include "../compiler.h"

extern "C" bool rust_miniscript_policy(std::string& policy);

bool BitcoinCore(const std::string& input_str)
{
    return ParsePolicy(input_str);
}

void MiniscriptPolicy(FuzzedDataProvider& provider) 
{
    std::string input_str{provider.ConsumeRemainingBytesAsString().c_str()};
    assert(BitcoinCore(input_str) == rust_miniscript_policy(input_str));
}