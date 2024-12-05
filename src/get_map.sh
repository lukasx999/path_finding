#!/usr/bin/env bash
set -euxo pipefail

wget https://openstreetmap.org/api/0.6/relation/65606 -O map.xml
