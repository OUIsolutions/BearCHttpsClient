---@param flag string
---@return boolean
function Is_present_in_argv(flag)
    for i = 1, #argv do
        if argv[i] == flag then
            return true
        end
    end
    return false
end
