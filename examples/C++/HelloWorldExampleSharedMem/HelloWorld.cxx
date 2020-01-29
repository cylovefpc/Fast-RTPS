// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file HelloWorld.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include "HelloWorld.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

HelloWorld::HelloWorld()
{
    // m_index com.eprosima.idl.parser.typecode.PrimitiveTypeCode@185d8b6
    m_index = 0;
    // m_message com.eprosima.idl.parser.typecode.StringTypeCode@67784306
    m_message ="";
    // m_data com.eprosima.idl.parser.typecode.ArrayTypeCode@335eadca
    memset(&m_data, 0, (1024) * 1);

}

HelloWorld::~HelloWorld()
{



}

HelloWorld::HelloWorld(const HelloWorld &x)
{
    m_index = x.m_index;
    m_message = x.m_message;
    m_data = x.m_data;
}

HelloWorld::HelloWorld(HelloWorld &&x)
{
    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_data = std::move(x.m_data);
}

HelloWorld& HelloWorld::operator=(const HelloWorld &x)
{

    m_index = x.m_index;
    m_message = x.m_message;
    m_data = x.m_data;

    return *this;
}

HelloWorld& HelloWorld::operator=(HelloWorld &&x)
{

    m_index = x.m_index;
    m_message = std::move(x.m_message);
    m_data = std::move(x.m_data);

    return *this;
}

size_t HelloWorld::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + 255 + 1;

    current_alignment += ((1024) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t HelloWorld::getCdrSerializedSize(const HelloWorld& data, size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);


    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.message().size() + 1;

    current_alignment += ((1024) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    return current_alignment - initial_alignment;
}

void HelloWorld::serialize(eprosima::fastcdr::Cdr &scdr) const
{

    scdr << m_index;
    scdr << m_message;
    scdr << m_data;

}

void HelloWorld::deserialize(eprosima::fastcdr::Cdr &dcdr)
{

    dcdr >> m_index;
    dcdr >> m_message;
    dcdr >> m_data;

}

/*!
 * @brief This function sets a value in member index
 * @param _index New value for member index
 */
void HelloWorld::index(uint32_t _index)
{
m_index = _index;
}

/*!
 * @brief This function returns the value of member index
 * @return Value of member index
 */
uint32_t HelloWorld::index() const
{
    return m_index;
}

/*!
 * @brief This function returns a reference to member index
 * @return Reference to member index
 */
uint32_t& HelloWorld::index()
{
    return m_index;
}

/*!
 * @brief This function copies the value in member message
 * @param _message New value to be copied in member message
 */
void HelloWorld::message(const std::string &_message)
{
m_message = _message;
}

/*!
 * @brief This function moves the value in member message
 * @param _message New value to be moved in member message
 */
void HelloWorld::message(std::string &&_message)
{
m_message = std::move(_message);
}

/*!
 * @brief This function returns a constant reference to member message
 * @return Constant reference to member message
 */
const std::string& HelloWorld::message() const
{
    return m_message;
}

/*!
 * @brief This function returns a reference to member message
 * @return Reference to member message
 */
std::string& HelloWorld::message()
{
    return m_message;
}
/*!
 * @brief This function copies the value in member data
 * @param _data New value to be copied in member data
 */
void HelloWorld::data(const std::array<char, 1024> &_data)
{
m_data = _data;
}

/*!
 * @brief This function moves the value in member data
 * @param _data New value to be moved in member data
 */
void HelloWorld::data(std::array<char, 1024> &&_data)
{
m_data = std::move(_data);
}

/*!
 * @brief This function returns a constant reference to member data
 * @return Constant reference to member data
 */
const std::array<char, 1024>& HelloWorld::data() const
{
    return m_data;
}

/*!
 * @brief This function returns a reference to member data
 * @return Reference to member data
 */
std::array<char, 1024>& HelloWorld::data()
{
    return m_data;
}

size_t HelloWorld::getKeyMaxCdrSerializedSize(size_t current_alignment)
{
	size_t current_align = current_alignment;






    return current_align;
}

bool HelloWorld::isKeyDefined()
{
   return false;
}

void HelloWorld::serializeKey(eprosima::fastcdr::Cdr &scdr) const
{
	(void) scdr;
	 
	 
	 
}
