# compile-if-found.ps1

# Full path of the file
$check = $args[0]
$file = $check+"/config.cpp"
$pboproject = "C:\Program Files (x86)\Mikero\DePboTools\bin\pboProject.exe"
$workspaceFolderBasename = $args[1]
$config_dayz_server_dir = $args[2]
$config_dayz_mikero_localmod = $args[3]
$workspaceFolder = $args[5]
$Parms = "-P -L=$($workspaceFolderBasename)$($check) +mod=$($config_dayz_server_dir)\\$($config_dayz_mikero_localmod)\\@ScarabyteDev$($check) $($workspaceFolder)\\$($check)"

if ((Test-Path -Path $file -PathType Leaf)) {    
    $Parms = $Parms.Split(" ")
    & "$pboproject" $Parms
}
else
{
    write-host "$($check)-Side not found. Skipping..."
}
