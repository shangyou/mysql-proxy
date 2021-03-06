/*
  +----------------------------------------------------------------------+
  | Swoole                                                               |
  +----------------------------------------------------------------------+
  | This source file is subject to version 2.0 of the Apache license,    |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.apache.org/licenses/LICENSE-2.0.html                      |
  | If you did not receive a copy of the Apache2.0 license and are unable|
  | to obtain it through the world-wide-web, please send a note to       |
  | license@swoole.com so we can mail you a copy immediately.            |
  +----------------------------------------------------------------------+
  | Author: Tianfeng Han  <mikan.tenny@gmail.com>                        |
  +----------------------------------------------------------------------+
*/

#include "embed.h"

//#include <swoole.h>
#include <iostream>

using namespace php;
using namespace std;

void test()
{
    cout << "hello world" << endl;
}

int main(int argc, char * argv[])
{
    php::VM vm(argc, argv);
    vm.eval("echo 'Hello World!';");
    vm.include("embed.php");

    auto a = constant("SWOOLE_BASE");
    cout << "SWOOLE_BASE = " << a.toInt() << endl;

    auto obj = php::newObject("Test");
    auto ret = obj.exec("getName");

    cout << ret.toString() << endl;

    obj.set("name", "Tianfeng");

    auto ret2 = obj.exec("getName");
    cout << ret2.toString() << endl;

    Array arr;
    arr.append(1234);
    arr.append(1234.02);
    arr.append(1234.03);
    arr.append(1234.04);
    arr.append("1234.05");
    var_dump(arr);

    Array arr2 = arr.slice(0, 2);
    var_dump(arr2);

    String s1 = "hello world";
    String s2 = s1.substr(0, 5);
    cout << "s2=" << s2.c_str() << endl;

//    swoole_add_function("test", (void*) test);

    return 0;
}
