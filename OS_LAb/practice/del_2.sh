#!/bin/sh

find . -type f -name "*.txt" -exec  sed '2~2d' {} +

