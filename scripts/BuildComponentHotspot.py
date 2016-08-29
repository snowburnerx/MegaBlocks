#!/usr/bin/python
from abc import ABCMeta
from abc import abstractmethod


class BuildComponentHotspot:
    __metaclass__ = ABCMeta

    def __init__(self, config):
        self.type = config['type']
        self.x = config['x']
        self.y = config['y']
        self.z = config['z']

    @abstractmethod
    def valid_connection(self, proposed_connection):
        pass

    @abstractmethod
    def get_robot_connection_movement(self):
        pass

    @abstractmethod
    def get_goal_vector(self):
        pass
