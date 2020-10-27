// SNMPpp: https://sourceforge.net/p/snmppp/
// SNMPpp project uses the MIT license. See LICENSE for details.
// Copyright (C) 2013 Stephane Charette <stephanecharette@gmail.com>

#pragma once

#include <SNMPpp/net-snmppp.hpp>
#include <SNMPpp/Session.hpp>
#include <SNMPpp/OID.hpp>
#include <SNMPpp/PDU.hpp>

#include <string>

namespace SNMPpp
{
    /** @file
     * Several C++ helpers for some of the common net-snmp "SET" actions.
     * Remember to free the response PDUs by calling SNMPpp::PDU::free() or
     * `netsnmp's snmp_pdu_free()`.
     */

    /** Send a PDU using the given SNMPpp::SessionHandle, and wait for a reply.
     * This is the method all other "set" functions call to perform the
     * underlying request->response sync with the SNMP server.
     * @note
     * - The *request* PDU is automatically freed before returning to the
     *   caller, even when an exception is thrown.
     * - The *response* PDU needs to be freed using SNMPpp::PDU::free().
     * - This will throw if an unexpected problem occurs.
     */
    SNMPpp::PDU sync( SNMPpp::SessionHandle &session, SNMPpp::PDU &request );

    /** Alias to SNMPpp::sync() for convenience, and to be consistent with the
     * various other SNMPpp::get...() calls.
     * @see SNMPpp::sync() to see additional exceptions this may throw.
     */
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, SNMPpp::PDU &pdu );

    /** Set a single OID
     * @note
     * - The response PDU needs to be freed using SNMPpp::PDU::free().
     * - This will throw if an unexpected problem occurs.
     * @see SNMPpp::sync() to see additional exceptions this may throw.
     */
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const bool &v ); // BOOLEAN
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const int &v ); // INTEGER32
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const long &v ); // INTEGER64
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const unsigned int &v ); // GAUGE32
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const long unsigned int &v ); // GAUGE64
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const std::string &v ); // STRING
    SNMPpp::PDU set( SNMPpp::SessionHandle &session, const SNMPpp::OID &o, const unsigned char v[], const unsigned int size ); // BITSTRING

};
