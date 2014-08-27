
//
// Copyright (c) 2014 Limit Point Systems, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// Test driver for vd_field.java

//$$SCRIBBLE: This is just a placeholder.  It will be
//            further developed as part of the field algebra project.

import bindings.java.*;

public class vd_field_t extends base_example
{
  static final String moduleName = "fields_java_binding";
  static final String className  = "vd_field_t";

  public vd_field_t()
  {
    super(moduleName);
  }

  public vd_field_t(String module_name)
  {
    super(module_name);
  }

  public static void usage()
  {
    String nl = System.getProperty("line.separator");

    StringBuffer sb = new StringBuffer();
    sb.append("Usage: java [-cp CLASSPATH] " + className
              + " [-option]").append(nl)
    .append(nl)
    .append("where options include:").append(nl)
    .append("    i_size (default = 1)").append(nl)
    .append("    -help  Print this message and exit.").append(nl)
    .append("    -h     Print this message and exit.").append(nl)
    .append(nl);

    System.out.println(sb);
    System.exit(1);
  }

  public static void main(String argv[])
  {
    // Handle command line arguments.

    if(argv.length > 0)
    {
      usage();
    }

    // Instantiate "this" class (loads the libraries, etc.).

    vd_field_t test = new vd_field_t();

    // Make the fiber_bundles namespace.

    fiber_bundles_namespace lns = new fiber_bundles_namespace(className);

    // Output a text version to stdout.

    //System.out.println(the_namespace.to_string());

    // Write namespace to file.

    test.writeHdfFile(lns, className +".hdf");

  }
}
