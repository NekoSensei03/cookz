class CfgPatches
{
    class CookZ_Sounds {};
};

class CfgSoundShaders
{
    class CookZ_Page_Flip_SoundShader
    {
        samples[] = {{"CookZ\sounds\page-flip",1}};
        volume = 1;
        frequency = 1;
        range = 7;
        rangeCurve[] = {{0,1}, {5,0.7}, {10,0}};
    };
};

class CfgSoundSets
{
    class CookZ_Page_Flip_SoundSet
    {
        soundShaders[] = {"CookZ_Page_Flip_SoundShader"};
        sound3DProcessingType = "character3DProcessingType";
        volumeCurve = "characterAttenuationCurve";
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
};