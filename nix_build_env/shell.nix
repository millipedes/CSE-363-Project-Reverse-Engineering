with import <nixpkgs> {}; {
  projectEnv = stdenv.mkDerivation {
    name = "ncurses";
    buildInputs = [stdenv file xxHash zlib libzip];
    propagateBuildInputes = [ncurses];
  };
}

