#pragma once

#ifndef MULTI_PROVIDER_HPP
#define MULTI_PROVIDER_HPP

#include "ValueProvider.hpp"

#include <memory>
#include <vector>
#include "../../Utility.hpp"

/// Returns the sum of the values of the passed providers
class MultiProvider : public ValueProvider
{
private:

    std::vector<std::unique_ptr<ValueProvider>> m_provider;

public:

    MultiProvider(std::vector<std::unique_ptr<ValueProvider>>& provider) : m_provider(std::move(provider))
    {
        for(auto it = begin(m_provider); it != end(m_provider); ++it)
            if((*it) == nullptr)
                throw std::runtime_error(utility::translateKey("ProviderNull"));
    }

    virtual float getValue() = 0;

    virtual void reset() override
    {
        for(auto it = begin(m_provider); it != end(m_provider); ++it)
            (*it)->reset();
    }

protected:

    const std::vector<std::unique_ptr<ValueProvider>>& getProvider() const
    {
        return m_provider;
    }
};

#endif //MULTI_PROVIDER_HPP