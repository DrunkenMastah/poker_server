((c++-mode . ((lsp-clients-clangd-args . ("--compile-commands-dir=build"
                                          "--pch-storage=memory"
                                          "--background-index"
                                          "-j=4"
                                          ))
              )))
((nil . ((cmake-ide-project-dir . "~/Documents/cpp/poker/server")
         (cmake-ide-build-dir . "~/Documents/cpp/poker/server/build")
         (cmake-ide-cmake-opts . "-DCMAKE_BUILD_TYPE=Debug ")
         (projectile-project-name . "poker server")
         (projectile-project-run-cmd . "cmake --build build --target run")
         (projectile-project-test-cmd . "cmake --build build --target test")
         (setq helm-ctest-build-dir "~/Projects/example/build")
         (helm-make-build-dir . "build")
         (helm-make-arguments . "-j4"))))
