from pb_stream import ProtobufWriter, ProtobufReader
from is_msgs.common_pb2 import Pose
from random import random
import json
from google.protobuf.json_format import MessageToJson
from time import time
import os

writer = ProtobufWriter('poses')
poses = []
for k in range(10000):
    pose = Pose()
    pose.position.x = random()
    pose.position.y = random()
    pose.position.z = k
    writer.insert(pose)
    poses.append(json.loads(MessageToJson(pose)))

writer.close()

t0 = time()
reader = ProtobufReader('poses')
while True:
    pose = reader.next(Pose())
    if not pose:
        break
t1 = time()

print('Read time: {:.3f}ms'.format((t1-t0)*1000.0))