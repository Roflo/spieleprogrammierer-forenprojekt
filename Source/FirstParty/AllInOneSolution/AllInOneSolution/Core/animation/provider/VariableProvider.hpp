#pragma once

#ifndef VARIABLE_PROVIDER_HPP
#define VARIABLE_PROVIDER_HPP

#include "../VariableHandler.hpp"

#include <exception>
#include <string>

/// Returns the value of a variable owned by someone else.
class VariableProvider : public ValueProvider
{
private:

    const VariableHandler* m_owner;
    std::string m_varName;

public:
    VariableProvider(const VariableHandler* owner, const std::string& varName) : m_owner(owner), m_varName(varName)
    {
        if(owner == nullptr)
            throw std::runtime_error(utility::replace(utility::translateKey("OwnerNull"), "VariableProvider"));
    }

    virtual float getValue() override
    {
        return m_owner->getValueOf(m_varName);
    }

    virtual VariableProvider* clone() const override
    {
        return new VariableProvider(m_owner, m_varName);
    }
};

#endif //VARIABLE_PROVIDER_HPP
