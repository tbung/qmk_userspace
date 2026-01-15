{
    description = "qmk";

    inputs = {
        nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
        # qmk_firmware = {
        #     type = "github";
        #     owner = "qmk";
        #     repo = "qmk_firmware";
        #     params = "submodules=1";
        #     # submodules = true;
        #     flake = false;
        # };
        qmk_firmware = {
            type = "git";
            url = "https://github.com/qmk/qmk_firmware";
            flake = false;
            # ref = "0.30.3";
            submodules = true;
        };
    };

    outputs = {self, nixpkgs, qmk_firmware}: let
        system = "x86_64-linux";
        pkgs = import nixpkgs { inherit system; };
    in {
        devShells.${system}.default = pkgs.mkShell {
            buildInputs = with pkgs; [
                qmk
            ];
            shellHook = ''
          echo "Welcome to the devShell!"
          '';
            # CPATH = builtins.concatStringsSep ":" [
            #     (lib.makeSearchPath "xtensa-esp-elf/xtensa-esp-elf/include" [pkgs.esp-idf-full.tools.xtensa-esp-elf])
            #     (lib.makeSearchPath "riscv32-esp-elf/riscv32-esp-elf/include" [pkgs.esp-idf-full.tools.riscv32-esp-elf])
            # ];
            QMK_HOME = qmk_firmware;
        };
    };
}
