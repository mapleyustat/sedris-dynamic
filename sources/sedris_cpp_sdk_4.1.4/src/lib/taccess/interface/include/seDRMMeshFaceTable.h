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

/** @file seDRMMeshFaceTable.h
@author Warren Macchi (Accent Geographic)
@brief Accessors to the seDRMMeshFaceTable (160) class.
*/

#ifndef _seDRMMeshFaceTable_h
#define _seDRMMeshFaceTable_h

#include "seDRMBase.h"

namespace sedris {

/** seDRMMeshFaceTable wraps the DRM <a href="../drm/classes/MeshFaceTable.htm">&lt;Mesh_Face_Table&gt;</a> class.
@author Warren Macchi
@version Revision: 1.8
@see seDRMBase
*/
class seDRMMeshFaceTable : public seDRMBase
{
public:

    /// Default constructor
    seDRMMeshFaceTable() {}

    /// Constructor for seDRM... class conversions
    seDRMMeshFaceTable( const seObject &other ) : seDRMBase(other) {}

    /// Get field <a href="../drm/classes/MeshFaceTable.htm#mesh_face_count">mesh_face_count</a>
    SE_Integer_Positive get_mesh_face_count()
    {
        DRMBASE_RET_FIELDS(Mesh_Face_Table, mesh_face_count);
    }

    /// Set field <a href="../drm/classes/MeshFaceTable.htm#mesh_face_count">mesh_face_count</a>
    void set_mesh_face_count( SE_Integer_Positive mesh_face_count )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Mesh_Face_Table, mesh_face_count, mesh_face_count);
    }

    /// Get field <a href="../drm/classes/MeshFaceTable.htm#maximum_vertices_per_face">maximum_vertices_per_face</a>
    SE_Integer_Positive get_maximum_vertices_per_face()
    {
        DRMBASE_RET_FIELDS(Mesh_Face_Table, maximum_vertices_per_face);
    }

    /// Set field <a href="../drm/classes/MeshFaceTable.htm#maximum_vertices_per_face">maximum_vertices_per_face</a>
    void set_maximum_vertices_per_face( SE_Integer_Positive maximum_vertices_per_face )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Mesh_Face_Table, maximum_vertices_per_face, maximum_vertices_per_face);
    }

    /// Get field <a href="../drm/classes/MeshFaceTable.htm#adjacent_face_table_present">adjacent_face_table_present</a>
    SE_Boolean get_adjacent_face_table_present()
    {
        DRMBASE_RET_FIELDS(Mesh_Face_Table, adjacent_face_table_present);
    }

    /// Set field <a href="../drm/classes/MeshFaceTable.htm#adjacent_face_table_present">adjacent_face_table_present</a>
    void set_adjacent_face_table_present( SE_Boolean adjacent_face_table_present )
    {
        DRMBASE_ALLOC_FIELDS;
        DRMBASE_SET_FIELDS(Mesh_Face_Table, adjacent_face_table_present, adjacent_face_table_present);
    }

    /** Set Mesh Face Table data.
       See the seHelperMeshFaceTable class for an easier interface for accessing
       mesh face table data.

       The @p number_faces parameter indicates the number of entries in the array
       @p mesh_face_table_data (and @p adjacent_face_table_data if required).

       @note The sum of @p start_face and @p number_faces must not be greater
             than the number of faces indicated in the mesh_face_count field
             of the &lt;Mesh Face Table&gt; object.
       @note If the adjacent_face_table_present field of the &lt;Mesh Face Table&gt;
             object is SE_TRUE, then @p adjacent_face_table_data must not be NULL.

       @note The user is responsible for allocating/deallocating the data memory.
       @see seHelperMeshFaceTable
    */
    virtual void putMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data = NULL );

    /** Get Mesh Face Table data.
       See the seHelperMeshFaceTable class for an easier interface for accessing
       mesh face table data.

       The @p number_faces parameter indicates the number of entries in the array
       @p mesh_face_table_data (and @p adjacent_face_table_data if required).

       @note The sum of @p start_face and @p number_faces must not be greater
             than the number of faces indicated in the mesh_face_count field
             of the &lt;Mesh Face Table&gt; object.

       @note The user is responsible for allocating/deallocating the data memory.
       @see seHelperMeshFaceTable
    */
    virtual void getMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        SE_Integer_Unsigned *mesh_face_table_data,
                        SE_Integer_Unsigned *adjacent_face_table_data = NULL );

    /** Gets the DRM class type this object can reference (mostly internal use).
        @warning Don't confuse with getDRMClass(), which is dependent on the
            actual type held by this DRM class object reference.
        @return SE_CLS_DRM_MESH_FACE_TABLE
    */
    virtual SE_DRM_Class getClassType() const
    {
        return SE_CLS_DRM_MESH_FACE_TABLE;
    }

};

} // namespace sedris

#endif // _seDRMMeshFaceTable_h