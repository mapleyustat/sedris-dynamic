/*
 * SRM API
 *
 * FILE       : srm_lce.cpp
 *
 * PROGRAMMERS: David Shen
 *
 * DESCRIPTION:
 *   This file is internal to the SRM API.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 * For other release dates/detailed changes, contact SAIC.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "srm_types.h"
#include "srm_ctypes.h"
#include "srm_internal.h"
#include "impl_srf_params.h"

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCE_GC
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLCE_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coord[4],
          SRM_Long_Float  dest_generic_coord[4]
)
{
    Impl_Status status = IMPL_VALID;

    SRM_LCE_Specific_Constants* gc_gd_spec=(SRM_LCE_Specific_Constants*)constants;

    for (int i = 0; i < 3; i++ )
    {
        dest_generic_coord[i] =
        gc_gd_spec->lococentre[i] +
        source_generic_coord[0]*gc_gd_spec->primary_axis[i] +
        source_generic_coord[1]*gc_gd_spec->secondary_axis[i] +
        source_generic_coord[2]*gc_gd_spec->xprod_rs[i];
    }
    dest_generic_coord[3] = 1.0;

    return status;
}


void
set_lce_constants
(
    const IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP *lce_srfp,
          SRM_LCE_Specific_Constants      *lce_spec
)
{
    _cross_product( lce_srfp->primary_axis, lce_srfp->secondary_axis, lce_spec->xprod_rs );
    for (int i=0; i<3; i++)
    {
        lce_spec->lococentre[i] = lce_srfp->lococentre[i];
        lce_spec->primary_axis[i] = lce_srfp->primary_axis[i];
        lce_spec->secondary_axis[i] = lce_srfp->secondary_axis[i];
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCC_LCE
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCC_LCE
(
          void           *constants,
    const SRM_Long_Float  source_generic_coord[4],
          SRM_Long_Float  dest_generic_coord[4]
)
{
    Impl_Status status = IMPL_VALID;

    SRM_LCE_Specific_Constants* lce_spec=(SRM_LCE_Specific_Constants*)constants;

    SRM_Long_Float p_minus_q[3];

    for (int i=0; i<3; i++)
    {
        p_minus_q[i] = source_generic_coord[i] - lce_spec->lococentre[i];
    }
    _dot_product( p_minus_q, lce_spec->primary_axis, &dest_generic_coord[0] );
    _dot_product( p_minus_q, lce_spec->secondary_axis, &dest_generic_coord[1] );
    _dot_product( p_minus_q, lce_spec->xprod_rs, &dest_generic_coord[2] );

    return status;
}
