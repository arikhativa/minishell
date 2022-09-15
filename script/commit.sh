#!/bin/bash

git log --skip=1 -1 --oneline --format=%s | sed 's/^.*: //'
