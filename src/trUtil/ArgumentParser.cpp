/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* @author Maxim Serebrennik
*/

#include <trUtil/ArgumentParser.h>

namespace trUtil
{
    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(bool& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(float& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(double& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(int& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(unsigned int& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(std::string& value)
    {
        mParam = new osg::ArgumentParser::Parameter(value);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::Parameter(const Parameter& param)
    {
        mParam = new osg::ArgumentParser::Parameter(param);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::~Parameter()
    {
        if (mParam != nullptr)
        {
            delete mParam;
            mParam = nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter& ArgumentParser::Parameter::operator = (const Parameter& param)
    {
        mParam = param.mParam;
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    inline bool ArgumentParser::Parameter::Valid(const char* str) const
    {
        return mParam->valid(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Parameter::Assign(const char* str)
    {
        return mParam->assign(str);
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter() const
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter&()
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator const osg::ArgumentParser::Parameter&() const
    {
        return *mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::Parameter::operator osg::ArgumentParser::Parameter*()
    {
        return mParam;
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::ArgumentParser(int* argc, char **argv)
    {
        mArgParser = std::make_unique<osg::ArgumentParser>(argc, argv);
        mAppUsage = std::make_unique<ApplicationUsage>(mArgParser->getApplicationUsage());
    }

    //////////////////////////////////////////////////////////////////////////
    ArgumentParser::~ArgumentParser()
    {       
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsOption(const char* str) const
    {
        return mArgParser->isOption(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsString(const char* str) const
    {
        return mArgParser->isString(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsNumber(const char* str) const
    {
        return mArgParser->isNumber(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsBool(const char* str) const
    {
        return mArgParser->isBool(str);
    }

    //////////////////////////////////////////////////////////////////////////
    void ArgumentParser::SetApplicationUsage(ApplicationUsage* usage)
    {
        mAppUsage.reset(usage);
        mArgParser->setApplicationUsage(mAppUsage.get()->operator osg::ApplicationUsage *());
    }

    //////////////////////////////////////////////////////////////////////////
    ApplicationUsage* ArgumentParser::GetApplicationUsage()
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    const ApplicationUsage* ArgumentParser::GetApplicationUsage() const
    {
        return mAppUsage.get();
    }

    //////////////////////////////////////////////////////////////////////////
    int& ArgumentParser::GetArgc()
    {
        return mArgParser->argc();
    }

    //////////////////////////////////////////////////////////////////////////
    char** ArgumentParser::GetArgv()
    {
        return mArgParser->argv();
    }

    //////////////////////////////////////////////////////////////////////////
    std::string ArgumentParser::GetApplicationName() const
    {
        return mArgParser->getApplicationName();
    }

    //////////////////////////////////////////////////////////////////////////
    int ArgumentParser::Find(const std::string& str) const
    {
        return mArgParser->find(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsOption(int pos) const
    {
        return mArgParser->isOption(pos);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsString(int pos) const
    {
        return mArgParser->isString(pos);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::IsNumber(int pos) const
    {
        return mArgParser->isNumber(pos);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::ContainsOptions() const
    {
        return mArgParser->containsOptions();
    }

    //////////////////////////////////////////////////////////////////////////
    void ArgumentParser::Remove(int pos, int num)
    {
        mArgParser->remove(pos, num);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Match(int pos, const std::string& str) const
    {
        return mArgParser->match(pos, str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str)
    {
        return mArgParser->read(str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1)
    {
        return mArgParser->read(str, value1);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2)
    {
        return mArgParser->read(str, value1, value2);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3)
    {
        return mArgParser->read(str, value1, value2, value3);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4)
    {
        return mArgParser->read(str, value1, value2, value3, value4);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5)
    {
        return mArgParser->read(str, value1, value2, value3, value4, value5);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6)
    {
        return mArgParser->read(str, value1, value2, value3, value4, value5, value6);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7)
    {
        return mArgParser->read(str, value1, value2, value3, value4, value5, value6, value7);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8)
    {
        return mArgParser->read(str, value1, value2, value3, value4, value5, value6, value7, value8);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str)
    {
        return mArgParser->read(pos, str);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1)
    {
        return mArgParser->read(pos, str, value1);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2)
    {
        return mArgParser->read(pos, str, value1, value2);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3)
    {
        return mArgParser->read(pos, str, value1, value2, value3);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4)
    {
        return mArgParser->read(pos, str, value1, value2, value3, value4);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5)
    {
        return mArgParser->read(pos, str, value1, value2, value3, value4, value5);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6)
    {
        return mArgParser->read(pos, str, value1, value2, value3, value4, value5, value6);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7)
    {
        return mArgParser->read(pos, str, value1, value2, value3, value4, value5, value6, value7);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Read(int pos, const std::string& str, Parameter value1, Parameter value2, Parameter value3, Parameter value4, Parameter value5, Parameter value6, Parameter value7, Parameter value8)
    {
        return mArgParser->read(pos, str, value1, value2, value3, value4, value5, value6, value7, value8);
    }

    //////////////////////////////////////////////////////////////////////////
    bool ArgumentParser::Errors(ErrorSeverity severity) const
    {
        return mArgParser->errors(static_cast<osg::ArgumentParser::ErrorSeverity>(severity));
    }
}