local function main()
    if Is_present_in_argv("swatch") then
        silver_chain.watch(
            "src",
            "src/imports",
            "BearHttpsClient",
            { CONST_FLAGS, TYPES_FLAG, GLOBALS_FLAG, FDECLARE_FLAG, FDEFINE_FLAG }
        )
        return
    end
end
main()
