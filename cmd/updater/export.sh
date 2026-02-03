#!/bin/bash

# Workspace symlink name matches repo (googlesql); readlink gives execroot path
BAZEL_GOOGLESQL=$(readlink bazel-googlesql)
CACHE_ROOT=$BAZEL_GOOGLESQL/../../
cp -r $CACHE_ROOT/* /tmp/
