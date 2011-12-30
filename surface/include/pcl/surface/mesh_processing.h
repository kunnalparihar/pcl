/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 *
 */

#ifndef PCL_MESH_PROCESSING_H_
#define PCL_MESH_PROCESSING_H_

#include <pcl/pcl_base.h>
#include <pcl/PolygonMesh.h>

namespace pcl
{
  /** \brief @b MeshProcessing represents the base class for mesh processing algorithms.
    * \author Alexandru Eugen Ichim
    * \ingroup surface
    */
  class MeshProcessing
  {
    public:
      typedef PolygonMesh::ConstPtr PolygonMeshConstPtr;

      /** \brief Constructor. */
      MeshProcessing () : input_mesh_ () {};

      void setInputMesh (pcl::PolygonMeshConstPtr &input) { input_mesh_ = input; }

      /** \brief Base method for surface reconstruction for all points given in
        * <setInputCloud (), setIndices ()>
        * \param output the resultant reconstructed surface model
        */
      void reconstruct (pcl::PolygonMesh &output);

    protected:
      virtual bool initCompute ();
      virtual void deinitCompute ();

      /** \brief Abstract surface reconstruction method. */
      virtual void performReconstruction (pcl::PolygonMesh &output) = 0;

      /** \brief Abstract class get name method. */
      virtual std::string getClassName () const { return (""); }

      pcl::PolygonMeshConstPtr input_mesh_;
  };
}

#endif  /* PCL_MESH_PROCESSING_H_ */
