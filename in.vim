let project_dir = $GIT . '/knowledge_extractor/'
let build_dir = project_dir . 'build/'

exe 'CMakeProjectDir' project_dir
exe 'CMakeBuildLocation' build_dir
exe 'MakeFile' build_dir .'Makefile'
exe 'MakeCmdlineArgs -j4'

"let command = project_dir . 'run/run.sh'
let command = "cd " . project_dir . 'run && rm activities*dat* && siox-inst posix fwrite'
exe "nnoremap <leader>t :!" . command . " <CR>"
exe "nnoremap <leader>m :Make <CR> :Make install <CR>"
