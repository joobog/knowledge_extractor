let project_dir = $GIT . '/siox_ml_plugin/'
let build_dir = project_dir . 'build/'

exe 'CMakeProjectDir' project_dir
exe 'CMakeBuildLocation' build_dir
exe 'MakeFile' build_dir .'Makefile'
exe 'MakeCmdlineArgs -j4'

"let command = build_dir . 'test/run.sh'
let command = project_dir . 'run/run.sh'
exe "nnoremap <leader>t :!" . command . " <CR>"
