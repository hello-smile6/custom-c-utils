{ pkgs }: {
  deps = [
    pkgs.cowsay
    pkgs.progress
    pkgs.pv
    pkgs.strace
    pkgs.man-db
    pkgs.gdb
    pkgs.ncat
    pkgs.gcc11
    pkgs.gcc-unwrapped.man
    # Give us a better build env
    pkgs.gccMultiStdenv
    pkgs.tinycc

    
  ];
  nativeBuildInputs=[
    pkgs.gcc11
    pkgs.gcc11.man
  ];
  env={
    # PATH1= "${pkgs.gcc11}:/usr/bin:/usr/local/bin:/usr/sbin:/usr/local/sbin:/home/runner/.nix-profile/bin";
    MANPATH="${pkgs.gcc-unwrapped.man}";
  };
}



