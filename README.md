# Development container

    docker build --tag mull-workshop docker/

    docker run --rm -it -v workspace:/workspace -v $(pwd)/source:/source:ro --name mull mull-workshop

    > make && mull-cxx --test-framework CustomTest -ide-reporter-show-killed /workspace/bc-test
    > make && mull-cxx --test-framework GoogleTest -ide-reporter-show-killed /workspace/bc-gtest


    > make && mull-cxx --test-framework CustomTest --ld-search-path /usr/lib/x86_64-linux-gnu/ -ide-reporter-show-killed /workspace/bc-test

    > make && mull-cxx --test-framework CustomTest --ld-search-path /usr/lib/x86_64-linux-gnu/ --compdb-path=/workspace/compile_commands.json -ide-reporter-show-killed /workspace/bc-test
