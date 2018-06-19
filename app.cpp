#include "stream_pb.hpp"
#include <is/msgs/common.pb.h>
#include <iostream>

using namespace is::common;

int main() {
    
    ProtobufWriter writer("poses_cpp");
    for (auto i = 0; i < 10; ++i) {
        Pose pose;
        auto position = pose.mutable_position();
        position->set_x(i*1.0);
        position->set_y(i*2.0);
        position->set_z(i*3.0);
        writer.insert(pose);
    }
    writer.close(); // must close file before instanciate ProtobufReader

    ProtobufReader reader("poses_cpp");
    while (true) {
        auto pose = reader.next<Pose>();
        if (!pose) {
            break;
        }
        pose->PrintDebugString();
    }

    return 0;
}