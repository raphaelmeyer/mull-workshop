# Development container

    docker build --tag mull-workshop docker/

    docker run --rm -it -v workspace:/workspace -v $(pwd)/source:/source:ro --name mull mull-workshop

    > make && mull-cxx --test-framework CustomTest -ide-reporter-show-killed /workspace/bc-test
    > make && mull-cxx --test-framework GoogleTest -ide-reporter-show-killed /workspace/bc-gtest
