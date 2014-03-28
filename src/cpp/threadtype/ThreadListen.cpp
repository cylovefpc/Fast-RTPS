/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastCdr is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/*
 * ThreadListen.cpp
 *
 *  Created on: Feb 25, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *      		grcanosa@gmail.com
 */

#include "eprosimartps/threadtype/ThreadListen.h"
#include "eprosimartps/CDRMessage.h"
#include "eprosimartps/writer/RTPSWriter.h"
#include "eprosimartps/reader/RTPSReader.h"
#include "eprosimartps/Participant.h"

using boost::asio::ip::udp;


namespace eprosima {
namespace rtps {

ThreadListen::ThreadListen() :
		m_participant_ptr(NULL),m_b_thread_ptr(NULL),
		m_listen_socket(m_io_service),
		m_first(true)
{
	m_MessageReceiver.threadListen_ptr = this;

}

ThreadListen::~ThreadListen()
{
	pWarning( "Removing thread " << m_b_thread_ptr->get_id() << std::endl);
	m_b_thread_ptr->interrupt();
}

void ThreadListen::listen() {
	//Initialize socket

	if(m_first)
	{
		pInfo ( BLUE << "Thread: " << m_b_thread_ptr->get_id() << " listening in IP: " <<m_listen_socket.local_endpoint() << DEF << endl) ;
		m_participant_ptr->m_endpointToListenThreadSemaphore->post();
		m_first = false;
	}
	while(1) //TODOG: Add more reasonable condition, something with boost::thread
	{
		//CDRMessage_t msg;
		CDRMessage::initCDRMsg(&m_MessageReceiver.rec_msg);
		//Try to block all associated readers
		std::size_t lengthbytes = m_listen_socket.receive_from(boost::asio::buffer((void*)m_MessageReceiver.rec_msg.buffer, m_MessageReceiver.rec_msg.max_size), m_sender_endpoint);
		m_MessageReceiver.rec_msg.length = lengthbytes;
		pDebugInfo (BLUE << "Message received of length: " << m_MessageReceiver.rec_msg.length << " from endpoint: " << m_sender_endpoint << DEF << endl);

		//Get address into Locator
		m_send_locator.port = m_sender_endpoint.port();
		LOCATOR_ADDRESS_INVALID(m_send_locator.address);
		for(int i=0;i<4;i++)
		{
			m_send_locator.address[i+12] = m_sender_endpoint.address().to_v4().to_bytes()[i];
		}
		try
		{
			m_MessageReceiver.processCDRMsg(m_participant_ptr->m_guid.guidPrefix,&m_send_locator,&m_MessageReceiver.rec_msg);
			pDebugInfo ("Message processed " << endl);

		}
		catch(int e)
		{
			pError( "Error processing message of type: " << e << std::endl);

		}
	}
}

void ThreadListen::init_thread() {
	if(!m_locList.empty()){
		m_first = true;
		udp::endpoint listen_endpoint(boost::asio::ip::udp::v4(),m_locList[0].port);
		m_listen_socket.open(boost::asio::ip::udp::v4());
		m_listen_socket.bind(listen_endpoint);
		m_b_thread_ptr = new boost::thread(&ThreadListen::listen,this);
	}
}



} /* namespace rtps */
} /* namespace eprosima */

