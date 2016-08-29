#!/usr/bin/python

from BuildComponentHotspot import BuildComponentHotspot


class BuildComponent:

    def __init__(self, config):
        self.name = config['name']
        self.bx = config['bx']
        self.by = config['by']
        self.bz = config['bz']

        self.hotspots = []

        for _spot in config['hotspots']:
            self.hotspots.append(BuildComponentHotspot(_spot))
