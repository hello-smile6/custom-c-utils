{ pkgs }: {
  deps = [
    pkgs.cowsay
    pkgs.progress
    pkgs.pv
    pkgs.strace
    pkgs.man-db
    pkgs.gdb
    pkgs.ncat
  ];
}
