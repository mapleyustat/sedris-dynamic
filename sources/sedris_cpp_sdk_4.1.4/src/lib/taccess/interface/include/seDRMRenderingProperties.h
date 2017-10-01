/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created: Wed Jul 26 23:47:08 2006
 *
 *  DO NOT EDIT THIS FILE! (Autogenerated)
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

/** @file seDRMRenderingProperties.h
@author Warren Macchi (Accent Geographic)
@brief Accessors to the seDRMRenderingProperties (223) class.
*/

#ifndef _seDRMRenderingProperties_h
#define _seDRMRenderingProperties_h

#include "seDRMBase.h"

namespace sedris {

/** seDRMRenderingProperties wraps the DRM <a href="../drm/classes/RenderingProperties.htm">&lt;Rendering_Properties&gt;</a> class.
@author Warren Macchi
@version Revision: 1.8
@see seDRMBase
*/
class seDRMRenderingProperties : public seDRMBase
{
public:

    /// Default constructor
    seDRMRenderingProperties() {}

    /// Constructor for seDRM... class conversions
    seDRMRenderingProperties( const seObject &other ) : seDRMBase(other) {}

    /// Get field <a href="../drm/classes/RenderingProperties.htm#fill_method">fill_method</a>
    SE_Pixel_Fill_Method get_fill_method()
    {
        DRMBASE_RET_FIELDS(Rendering_Properties, fill_method);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#fill_method">fill_method</a>
    void set_fill_method( SE_Pixel_Fill_Method fill_method )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, fill_method, fill_method);
    }

    /// Get field <a href="../drm/classes/RenderingProperties.htm#shading_method">shading_method</a>
    SE_Shading_Method get_shading_method()
    {
        DRMBASE_RET_FIELDS(Rendering_Properties, shading_method);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#shading_method">shading_method</a>
    void set_shading_method( SE_Shading_Method shading_method )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, shading_method, shading_method);
    }

    /// Get field <a href="../drm/classes/RenderingProperties.htm#colour_binding">colour_binding</a>
    SE_Colour_Binding get_colour_binding()
    {
        DRMBASE_RET_FIELDS(Rendering_Properties, colour_binding);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#colour_binding">colour_binding</a>
    void set_colour_binding( SE_Colour_Binding colour_binding )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, colour_binding, colour_binding);
    }

    /// Get field <a href="../drm/classes/RenderingProperties.htm#style">style</a>
    SE_Display_Style get_style()
    {
        DRMBASE_RET_FIELDS(Rendering_Properties, style);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#style">style</a>
    void set_style( SE_Display_Style style )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, style, style);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#style">style</a> by parameter list (Set type)
    void set_style
    (
         SE_Integer_Unsigned Solid,
         SE_Integer_Unsigned Wireframe
    )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, style.member.Solid, Solid);
        DRMBASE_SET_FIELDS(Rendering_Properties, style.member.Wireframe, Wireframe);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#style_Solid">style_Solid</a>
    void set_style_Solid( SE_Integer_Unsigned Solid )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, style.member.Solid, Solid);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#style_Wireframe">style_Wireframe</a>
    void set_style_Wireframe( SE_Integer_Unsigned Wireframe )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, style.member.Wireframe, Wireframe);
    }

    /// Get field <a href="../drm/classes/RenderingProperties.htm#side">side</a>
    SE_Display_Side get_side()
    {
        DRMBASE_RET_FIELDS(Rendering_Properties, side);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#side">side</a>
    void set_side( SE_Display_Side side )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, side, side);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#side">side</a> by parameter list (Set type)
    void set_side
    (
         SE_Integer_Unsigned Front,
         SE_Integer_Unsigned Back
    )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, side.member.Front, Front);
        DRMBASE_SET_FIELDS(Rendering_Properties, side.member.Back, Back);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#side_Front">side_Front</a>
    void set_side_Front( SE_Integer_Unsigned Front )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, side.member.Front, Front);
    }

    /// Set field <a href="../drm/classes/RenderingProperties.htm#side_Back">side_Back</a>
    void set_side_Back( SE_Integer_Unsigned Back )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Rendering_Properties, side.member.Back, Back);
    }

    /** Gets the DRM class type this object can reference (mostly internal use).
        @warning Don't confuse with getDRMClass(), which is dependent on the
            actual type held by this DRM class object reference.
        @return SE_CLS_DRM_RENDERING_PROPERTIES
    */
    virtual SE_DRM_Class getClassType() const
    {
        return SE_CLS_DRM_RENDERING_PROPERTIES;
    }

};

} // namespace sedris

#endif // _seDRMRenderingProperties_h