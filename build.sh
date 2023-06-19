export SCORE_SDK=/home/grybouilli/Documents/ossia/score/sdk/3.1.10
export OSSIA_SDK=/opt/ossia-sdk
export PATH=$OSSIA_SDK/llvm/bin:$PATH
export CC=clang
export CXX=clang++

cmake -S . \
        -B testing-plugin-build-release \
        -GNinja \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DCMAKE_MODULE_PATH="$SCORE_SDK/usr/lib/cmake/score" \
        -DSCORE_SDK="$SCORE_SDK/usr" \
        -DOSSIA_SDK="$OSSIA_SDK" \
        -DCMAKE_INSTALL_PREFIX="/home/grybouilli/Documents/ossia/score/packages/my_plugin" \
        -DCMAKE_PREFIX_PATH="/usr/lib/libtorch-cpu"
