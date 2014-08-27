#! /usr/bin/env python
#
# Copyright (c) 2014 Limit Point Systems, Inc. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

from sheaves_python_binding import *
from fiber_bundles_python_binding import *
import os

TRUE = 1
FALSE = 0

###############################################################################
# main(file_name):
###############################################################################

def main(argv):

    ## Handle command line arguments.
    
    size_0 = 1
    if(len(argv) >= 2): size_0 = int(argv[1])

    size_1 = 1
    if(len(argv) >= 3): size_1 = int(argv[2])

    path = argv[0][0:-3] ## Splice off ".py" from name
    name = (os.path.split(path))[1]

    ## Create the namespace poset.
    
    lns = fiber_bundles_namespace(name)
    lns.get_read_write_access()

    lmesh = structured_block_2d.new_host(lns, name + "_mesh")

    lblock = structured_block_2d(lmesh, size_0, size_1, TRUE)
    lblock.get_read_write_access()
    lblock.put_name(name +"_block", TRUE, FALSE)

    ##lmesh.to_stream()

    ## Test the refinement map.

    print "\n##### Begin refinement map test ###############\n"

    lpt = chart_point_2d(lblock.index(), -1.0, -1.0)

    lref_pt = chart_point_2d()

    coords = [-1.0, -0.5, 0.0, 0.5, 1.0]

    for lxcoord in coords:
        lpt.put_local_coord(0, lxcoord)
        for lycoord in coords:
            lpt.put_local_coord(1,  lycoord)
            lblock.refine_point_pa(lpt, lref_pt)
            print "point:", lpt.to_string(),
            print "\trefined point:", lref_pt.to_string(),
            lblock.unrefine_point_pa(lref_pt, lpt)
            print "\tunrefined point:", lpt.to_string(), "\n"
                  
    print "\n##### End refinement map test ###############\n"

    ## Cleanup.

    lblock.detach_from_state()
    lmesh.release_access()

    ##  Write the namespace to a file.

    sa = storage_agent(name +".hdf")
    sa.write_entire(lns)

    del lns

    
###############################################################################

if __name__ == '__main__':  
    import sys
    
    if len(sys.argv) > 3:
        print 'Usage: ' + sys.argv[0] + ' [size_0 size_1]' 
    else:
        main(sys.argv)
