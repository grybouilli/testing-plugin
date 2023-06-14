#!/bin/bash
rm -rf release
mkdir -p release

cp -rf testing-plugin *.{hpp,cpp,txt,json} LICENSE release/

mv release score-addon-testing-plugin
7z a score-addon-testing-plugin.zip score-addon-testing-plugin
