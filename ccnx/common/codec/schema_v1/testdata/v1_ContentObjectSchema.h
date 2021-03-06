/*
 * Copyright (c) 2013-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC)
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
 * This is from the version 1 codec.  All the test vectors in this directory (e.g. interest_nameA.h)
 * are encoded using these constants.  These are no longer used for any functional code, only to interpret the test vectors.
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright (c) 2013-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC).  All rights reserved.
 */

#ifndef Libccnx_v1_ContentObjectSchema_h
#define Libccnx_v1_ContentObjectSchema_h

#include <ccnx/common/codec/testdata/tlv_Schema.h>

#define T_CONTENTOBJECT 0x0002

// these are the array indicies used to store the TlvExtent for the item
typedef enum {
    // top level entities
    V1_MANIFEST_OBJ_NAME            = 0,
    V1_MANIFEST_OBJ_CONTENTOBJECT   = 1,  // the top container
    V1_MANIFEST_OBJ_NAMEAUTH        = 2,
    V1_MANIFEST_OBJ_PAYLOADTYPE     = 3,
    V1_MANIFEST_OBJ_PAYLOAD         = 4,
    V1_MANIFEST_OBJ_SIGBITS         = 5,

    // inside the name authenticator
    V1_MANIFEST_OBJ_KEYID           = 6,
    V1_MANIFEST_OBJ_CRYPTO_SUITE    = 7,
    V1_MANIFEST_OBJ_KEY             = 8,
    V1_MANIFEST_OBJ_CERT            = 9,
    V1_MANIFEST_OBJ_KEYNAME         = 10,
    V1_MANIFEST_OBJ_KEYNAME_NAME    = 11,
    V1_MANIFEST_OBJ_KEYNAME_OBJHASH = 12,

    // inside the protocol information
    V1_MANIFEST_OBJ_METADATA        = 13,

    // inside metadata
    V1_MANIFEST_OBJ_OBJ_TYPE        = 14,
    V1_MANIFEST_OBJ_CREATE_TIME     = 15,
    V1_MANIFEST_OBJ_EXPIRY_TIME     = 16,

    // inside signature block
    V1_MANIFEST_OBJ_ValidationPayload = 17,
    V1_MANIFEST_OBJ_ENDSEGMENT      = 18,
    V1_MANIFEST_OBJ_PUBKEY          = 19,

    V1_MANIFEST_OBJ_ValidationAlg   = 20,
    V1_MANIFEST_OBJ_SigningTime     = 21,
    V1_MANIFEST_OBJ_BODYEND         = 22
} SchemaV1ManifestContentObjectBody;

typedef enum {
    V1_MANIFEST_OBJ_OPTHEAD     = 0,
    V1_MANIFEST_OBJ_E2EFRAG     = 2,
    V1_MANIFEST_OBJ_FIXEDHEADER = 3,
    V1_MANIFEST_OBJ_RecommendedCacheTime = 4,
    V1_MANIFEST_OBJ_HEADEND     = 5
} SchemaV1ManifestContentObjectHeaders;

#endif // Libccnx_tlv_ContentObjectSchema_h
