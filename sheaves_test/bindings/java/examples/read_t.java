
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

//
// Class read_t
//

import bindings.java.*;

public class read_t extends base_example
{
  static final String moduleName = "sheaves_java_binding";
  static final String className  = "read_t";

  public read_t()
  {
    super(moduleName);
  }

  public read_t(String module_name)
  {
    super(module_name);
  }

  public static void usage()
  {
    String nl = System.getProperty("line.separator");

    StringBuffer sb = new StringBuffer();
    sb.append("Usage: java [-cp CLASSPATH] " + className
              + " hdf_file_name").append(nl);

    System.out.println(sb);
    System.exit(1);
  }

  public static void main(String[] args)
  {

    // Handle command line arguments.

    String fileName = null;

    if(args.length < 1)
    {
      usage();
    }
    else
    {
      fileName = args[0];
    }

    // Instantiate "this" class (loads the libraries, etc.).

    read_t test = new read_t();

    // Make the namespace poset
    // (Note: We have to supply the default args in Java).

    namespace_poset the_namespace =
      new namespace_poset("test", 8, 16, 4);

    // Read the namespace poset from the file.

    test.readHdfFile(the_namespace, fileName);

    // Output a text version to stdout.

    System.out.println(the_namespace.to_string());

  }
}
