/*
 * Copyright (c) 2014-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX OR PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ################################################################################
 * #
 * # PATENT NOTICE
 * #
 * # This software is distributed under the BSD 2-clause License (see LICENSE
 * # file).  This BSD License does not make any patent claims and as such, does
 * # not act as a patent grant.  The purpose of this section is for each contributor
 * # to define their intentions with respect to intellectual property.
 * #
 * # Each contributor to this source code is encouraged to state their patent
 * # claims and licensing mechanisms for any contributions made. At the end of
 * # this section contributors may each make their own statements.  Contributor's
 * # claims and grants only apply to the pieces (source code, programs, text,
 * # media, etc) that they have contributed directly to this software.
 * #
 * # There is no guarantee that this section is complete, up to date or accurate. It
 * # is up to the contributors to maintain their portion of this section and up to
 * # the user of the software to verify any claims herein.
 * #
 * # Do not remove this header notification.  The contents of this section must be
 * # present in all distributions of the software.  You may only modify your own
 * # intellectual property statements.  Please provide contact information.
 *
 * - Palo Alto Research Center, Inc
 * This software distribution does not grant any rights to patents owned by Palo
 * Alto Research Center, Inc (PARC). Rights to these patents are available via
 * various mechanisms. As of January 2016 PARC has committed to FRAND licensing any
 * intellectual property used by its contributions to this software. You may
 * contact PARC at cipo@parc.com for more information or visit http://www.ccnx.org
 */
/**
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright (c) 2014-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC).  All rights reserved.
 */

#include <config.h>

#include <ccnx/common/codec/schema_v1/ccnxCodecSchemaV1_CryptoSuite.h>


bool
ccnxCodecSchemaV1CryptoSuite_ParcToTlv(PARCCryptoSuite parcSuite, CCNxCodecSchemaV1TlvDictionary_CryptoSuite *outputValue)
{
    bool matchFound = false;
    switch (parcSuite) {
        case PARCCryptoSuite_RSA_SHA256:
            *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_RsaSha256;
            matchFound = true;
            break;

        case PARCCryptoSuite_DSA_SHA256:
            // not supported yet
            break;

        case PARCCryptoSuite_RSA_SHA512:
            // not supported yet
            break;

        case PARCCryptoSuite_HMAC_SHA256:
            *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_HmacSha256;
            matchFound = true;
            break;

        case PARCCryptoSuite_HMAC_SHA512:
            // not supported yet
            break;

        case PARCCryptoSuite_NULL_CRC32C:
            *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_CRC32C;
            matchFound = true;
            break;

        default:
            // unknown
            break;
    }
    return matchFound;
}

bool
ccnxCodecSchemaV1CryptoSuite_TlvToParc(CCNxCodecSchemaV1TlvDictionary_CryptoSuite tlvValue, PARCCryptoSuite *outputSuite)
{
    bool matchFound = false;
    switch (tlvValue) {
        case CCNxCodecSchemaV1TlvDictionary_CryptoSuite_RsaSha256:
            *outputSuite = PARCCryptoSuite_RSA_SHA256;
            matchFound = true;
            break;

        case CCNxCodecSchemaV1TlvDictionary_CryptoSuite_CRC32C:
            *outputSuite = PARCCryptoSuite_NULL_CRC32C;
            matchFound = true;
            break;

        case CCNxCodecSchemaV1TlvDictionary_CryptoSuite_HmacSha256:
            *outputSuite = PARCCryptoSuite_HMAC_SHA256;
            matchFound = true;
            break;

        case CCNxCodecSchemaV1TlvDictionary_CryptoSuite_EcSecp256K1:
            // not supported yet
            break;

        default:
            // unknown
            break;
    }
    return matchFound;
}

bool
ccnxCodecSchemaV1CryptoSuite_SignAndHashToTlv(PARCSigningAlgorithm signAlgorithm, PARCCryptoHashType hashType, CCNxCodecSchemaV1TlvDictionary_CryptoSuite *outputValue)
{
    bool matchFound = false;
    switch (signAlgorithm) {
        case PARCSigningAlgorithm_RSA: {
            switch (hashType) {
                case PARCCryptoHashType_SHA256:
                    *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_RsaSha256;
                    matchFound = true;

                default:
                    break;
            }
            break;
        }

        case PARCSigningAlgorithm_HMAC: {
            switch (hashType) {
                case PARCCryptoHashType_SHA256:
                    *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_HmacSha256;
                    matchFound = true;
                default:
                    break;
            }
            break;
        }

        case PARCSigningAlgortihm_NULL: {
            switch (hashType) {
                case PARCCryptoHashType_CRC32C:
                    *outputValue = CCNxCodecSchemaV1TlvDictionary_CryptoSuite_CRC32C;
                    matchFound = true;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
    return matchFound;
}

