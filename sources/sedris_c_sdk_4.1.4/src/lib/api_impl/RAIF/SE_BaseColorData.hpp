// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_BaseColorData.hpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definitions for SE_BaseColorData.
//              Vendors implementing any color data classes are expected to
//              subclass them to this base class.
//
// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#ifndef _SE_BASE_COLOR_DATA_HPP_INCLUDED
#define _SE_BASE_COLOR_DATA_HPP_INCLUDED

#include "SE_InternalObject.hpp"

class SE_ControlLink;
class SE_Context;

class SE_BaseColorData : public SE_InternalObject
{

public:

    SE_BaseColorData(RAIFManager *raif_manager,
		     ObjectReference *objRef, SE_DRM_Class tag );

    virtual ~SE_BaseColorData();

    // returns the fields of the color object, converting them
    // to the color model in the context as needed.
    //
    virtual SE_FIELDS_PTR fields(SE_Status_Code *status_ptr,
				 SE_Context *context,
				 SE_Boolean *not_orig_fields);

    // utility function to convert color fields to another
    // color model.
    //
    static SE_Boolean convert_color(
			    SE_Colour_Model      cmodel,
			    SE_DRM_Class_Fields *cfields);

private:

    typedef struct _CacheColorFields
    {
        SE_DRM_Class_Fields       fields;
        SE_Colour_Model           color_model;
        SE_ControlLink           *control_link;
        struct _CacheColorFields *next;
    } CacheColorFields;

    // keeps a cache of converted colors
    CacheColorFields *_cache_fieldList;
};

#endif