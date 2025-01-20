<template>
  <div class="svg" v-if="active">
    <svg v-if="type=='Very Unsatisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="url(#paint0_radial_1588_9376)"/>
    <path d="M19.6029 7.03291C19.9159 6.92405 20.2579 7.08952 20.3667 7.4025C20.4756 7.71548 20.3101 8.05745 19.9971 8.16631L19.6029 7.03291ZM15.3971 9.76631C15.0842 9.87517 14.7422 9.7097 14.6333 9.39672C14.5245 9.08374 14.6899 8.74177 15.0029 8.63291L15.3971 9.76631ZM19.9971 8.16631L15.3971 9.76631L15.0029 8.63291L19.6029 7.03291L19.9971 8.16631Z" fill="#222230"/>
    <path d="M5.04369 6.65191C4.74088 6.51733 4.3863 6.6537 4.25172 6.95651C4.11713 7.25932 4.25351 7.6139 4.55632 7.74848L5.04369 6.65191ZM8.15632 9.34848C8.45913 9.48306 8.81371 9.34669 8.94829 9.04388C9.08287 8.74107 8.9465 8.38649 8.64369 8.25191L8.15632 9.34848ZM4.55632 7.74848L8.15632 9.34848L8.64369 8.25191L5.04369 6.65191L4.55632 7.74848Z" fill="#222230"/>
    <path d="M15.2045 11.9275C15.6838 12.3099 16.3348 12.556 17.0587 12.5809C17.9128 12.6103 18.6868 12.3255 19.2094 11.8545" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M7.78992 11.4593C7.4145 11.7187 6.91861 11.8681 6.37995 11.8495C5.7444 11.8277 5.1843 11.5766 4.82048 11.2002" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M12.196 16.2033C13.932 16.489 15.3599 17.5173 16.2092 18.9121C16.3816 19.1951 16.7507 19.2848 17.0338 19.1125C17.3168 18.9401 17.4065 18.571 17.2342 18.288C16.2107 16.6073 14.4864 15.3642 12.3909 15.0192C9.78957 14.591 7.28823 15.6564 5.76149 17.5845C5.55578 17.8443 5.59961 18.2216 5.8594 18.4273C6.11919 18.6331 6.49655 18.5892 6.70226 18.3294C7.96929 16.7294 10.042 15.8487 12.196 16.2033Z" fill="#A1410A"/>
    <defs>
    <radialGradient id="paint0_radial_1588_9376" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(20 6.33333) rotate(115.058) scale(28.3333)">
    <stop stop-color="#FFC42E"/>
    <stop offset="0.865775" stop-color="#F2600E"/>
    <stop offset="1" stop-color="#FF922E"/>
    </radialGradient>
    </defs>
    </svg>

    <svg v-else-if="type=='Unsatisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="url(#paint0_radial_1588_9387)"/>
    <path d="M7.59349 10.2003C7.90879 10.9287 8.7108 11.422 9.62112 11.3722C10.6044 11.3184 11.393 10.6484 11.555 9.80027" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M21.0897 12.7212C20.5597 13.4042 19.5716 13.6905 18.6356 13.3632C17.6063 13.0034 16.9899 12.024 17.1377 11.0732" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M12.2218 16.4157C11.2568 16.2204 10.3016 16.2953 9.43264 16.5879C9.11859 16.6936 8.77829 16.5247 8.67256 16.2107C8.56683 15.8966 8.73571 15.5563 9.04976 15.4506C10.1133 15.0926 11.2826 15.0013 12.4598 15.2395C13.82 15.5148 14.9986 16.191 15.8955 17.12C16.1257 17.3584 16.119 17.7382 15.8806 17.9684C15.6422 18.1985 15.2623 18.1919 15.0322 17.9535C14.2988 17.1938 13.3361 16.6412 12.2218 16.4157Z" fill="#E55D0F"/>
    <defs>
    <radialGradient id="paint0_radial_1588_9387" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(12.6 9.4) rotate(72.2724) scale(25.6164 44.1226)">
    <stop stop-color="#FFE456"/>
    <stop offset="0.652656" stop-color="#FFBD12"/>
    <stop offset="1" stop-color="#FFCB12"/>
    </radialGradient>
    </defs>
    </svg>

    <svg v-else-if="type=='Neutral'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="url(#paint0_radial_1588_9396)"/>
    <circle cx="10.6" cy="14.2004" r="1.8" fill="#222230"/>
    <circle cx="21" cy="14.2004" r="1.8" fill="#222230"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M11.6863 19.7002C11.3073 19.7002 11 20.0136 11 20.4002C11 20.7868 11.3073 21.1002 11.6863 21.1002H20.3137C20.6927 21.1002 21 20.7868 21 20.4002C21 20.0136 20.6927 19.7002 20.3137 19.7002H11.6863Z" fill="#E55D0F"/>
    <defs>
    <radialGradient id="paint0_radial_1588_9396" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(16 8.6) rotate(90) scale(23.4)">
    <stop stop-color="#FFE456"/>
    <stop offset="0.742739" stop-color="#FFBD12"/>
    <stop offset="1" stop-color="#FFCB12"/>
    </radialGradient>
    </defs>
    </svg>

    <svg v-else-if="type=='Satisfied'" width="34" height="32" viewBox="0 0 34 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="url(#paint0_radial_1588_9405)"/>
    <circle cx="26.5333" cy="17.2" r="7.2" fill="url(#paint1_radial_1588_9405)" fill-opacity="0.7"/>
    <circle cx="7.86667" cy="13.2" r="7.2" fill="url(#paint2_radial_1588_9405)" fill-opacity="0.7"/>
    <path d="M16.3737 10.0617C16.0781 9.52715 15.472 9.10611 14.7239 8.98555C13.9757 8.865 13.2681 9.07438 12.8195 9.48903" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M25.7199 11.5676C25.4243 11.033 24.8182 10.612 24.07 10.4914C23.3219 10.3709 22.6143 10.5802 22.1657 10.9949" stroke="#222230" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M13.7803 13.1902C14.0978 13.0952 14.4322 13.2755 14.5271 13.593C14.922 14.9127 16.1647 16.084 17.8734 16.4529C19.5821 16.8218 21.1973 16.2674 22.1015 15.2281C22.319 14.9781 22.698 14.9517 22.948 15.1692C23.198 15.3867 23.2244 15.7657 23.0069 16.0157C21.7846 17.4206 19.7083 18.0766 17.6202 17.6259C15.5322 17.1751 13.9113 15.721 13.3775 13.937C13.2825 13.6195 13.4629 13.2852 13.7803 13.1902Z" fill="#E55D0F"/>
    <defs>
    <radialGradient id="paint0_radial_1588_9405" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(20.6667 6.33333) rotate(112.567) scale(27.7949)">
    <stop stop-color="#FFE456"/>
    <stop offset="0.712022" stop-color="#FFBD12"/>
    <stop offset="1" stop-color="#FFCB12"/>
    </radialGradient>
    <radialGradient id="paint1_radial_1588_9405" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(26.5333 17.2) rotate(90) scale(7.2)">
    <stop offset="0.0714713" stop-color="#E55D0F" stop-opacity="0.7"/>
    <stop offset="1" stop-color="#FFCF32" stop-opacity="0"/>
    </radialGradient>
    <radialGradient id="paint2_radial_1588_9405" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(7.86667 13.2) rotate(90) scale(7.2)">
    <stop offset="0.0714713" stop-color="#E55D0F" stop-opacity="0.7"/>
    <stop offset="1" stop-color="#FFCF32" stop-opacity="0"/>
    </radialGradient>
    </defs>
    </svg>

    <svg v-else-if="type=='Very Satisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <mask id="mask0_1588_9416" style="mask-type:alpha" maskUnits="userSpaceOnUse" x="0" y="0" width="32" height="32">
    <circle cx="16" cy="16" r="16" fill="url(#paint0_radial_1588_9416)"/>
    </mask>
    <g mask="url(#mask0_1588_9416)">
    <circle cx="16" cy="16" r="16" fill="url(#paint1_radial_1588_9416)"/>
    <circle cx="6.66667" cy="11.9997" r="10.6667" fill="url(#paint2_radial_1588_9416)" fill-opacity="0.9"/>
    <circle cx="30" cy="17.9997" r="10.6667" fill="url(#paint3_radial_1588_9416)" fill-opacity="0.9"/>
    <path d="M17.9334 20.6715C21.7013 21.3991 25.35 19.046 26.278 15.3714C26.3367 15.1389 26.206 14.9038 25.9828 14.8162C21.7313 13.1482 17.2098 12.275 12.6429 12.24C12.4032 12.2382 12.1943 12.4077 12.1622 12.6454C11.6552 16.4013 14.1654 19.9438 17.9334 20.6715Z" fill="url(#paint4_linear_1588_9416)"/>
    <path d="M13.61 5.44175L17.2536 8.60663L12.8515 9.36918" stroke="#222230" stroke-width="1.6" stroke-linecap="round" stroke-linejoin="round"/>
    <path d="M27.5625 8.13598L23.0025 9.71661L26.8041 12.0634" stroke="#222230" stroke-width="1.6" stroke-linecap="round" stroke-linejoin="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M23.865 19.1691C22.2671 20.4784 20.1203 21.0939 17.9334 20.6716C15.7464 20.2492 13.9832 18.8786 12.9876 17.0684C14.5856 15.7591 16.7324 15.1436 18.9193 15.5659C21.1063 15.9883 22.8695 17.3589 23.865 19.1691Z" fill="url(#paint5_linear_1588_9416)"/>
    </g>
    <defs>
    <radialGradient id="paint0_radial_1588_9416" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(16 8) rotate(90) scale(28.2)">
    <stop stop-color="#FFE456"/>
    <stop offset="0.712022" stop-color="#FFBD12"/>
    <stop offset="1" stop-color="#FFCB12"/>
    </radialGradient>
    <radialGradient id="paint1_radial_1588_9416" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(16 8) rotate(90) scale(28.2)">
    <stop stop-color="#FFE456"/>
    <stop offset="0.712022" stop-color="#FFBD12"/>
    <stop offset="1" stop-color="#FFCB12"/>
    </radialGradient>
    <radialGradient id="paint2_radial_1588_9416" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(6.66667 11.9997) rotate(90) scale(10.6667)">
    <stop offset="0.0714713" stop-color="#E55D0F" stop-opacity="0.7"/>
    <stop offset="1" stop-color="#FFCF32" stop-opacity="0"/>
    </radialGradient>
    <radialGradient id="paint3_radial_1588_9416" cx="0" cy="0" r="1" gradientUnits="userSpaceOnUse" gradientTransform="translate(30 17.9997) rotate(90) scale(10.6667)">
    <stop offset="0.0714713" stop-color="#E55D0F" stop-opacity="0.7"/>
    <stop offset="1" stop-color="#FFCF32" stop-opacity="0"/>
    </radialGradient>
    <linearGradient id="paint4_linear_1588_9416" x1="19.2986" y1="13.6021" x2="17.9334" y2="20.6715" gradientUnits="userSpaceOnUse">
    <stop stop-color="#CB500A"/>
    <stop offset="1" stop-color="#D45308"/>
    </linearGradient>
    <linearGradient id="paint5_linear_1588_9416" x1="19.2986" y1="13.6022" x2="17.9333" y2="20.6716" gradientUnits="userSpaceOnUse">
    <stop stop-color="#E55D0F"/>
    <stop offset="1" stop-color="#E55D0F" stop-opacity="0.7"/>
    </linearGradient>
    </defs>
    </svg>
  </div>
  <div class="svg" v-else>
    <svg v-if="type=='Very Unsatisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="#98A0A9"/>
    <circle cx="16" cy="16" r="15.75" stroke="#525280" stroke-opacity="0.18" stroke-width="0.5"/>
    <path d="M19.8 9.59998L15.2 11.2" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M4.80005 9.19983L8.40005 10.7998" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M15.2046 13.9278C15.6839 14.3103 16.3349 14.5564 17.0588 14.5813C17.9129 14.6107 18.6869 14.3259 19.2095 13.8549" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M7.78999 13.4589C7.41458 13.7183 6.91868 13.8677 6.38003 13.8492C5.74447 13.8273 5.18438 13.5763 4.82056 13.1998" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M12.196 18.2033C13.932 18.489 15.36 19.5173 16.2093 20.9121C16.3816 21.1951 16.7508 21.2848 17.0338 21.1125C17.3168 20.9401 17.4065 20.571 17.2342 20.288C16.2108 18.6073 14.4865 17.3642 12.3909 17.0192C9.7896 16.591 7.28826 17.6564 5.76152 19.5845C5.55581 19.8443 5.59964 20.2216 5.85943 20.4273C6.11922 20.6331 6.49658 20.5892 6.70229 20.3294C7.96932 18.7294 10.042 17.8487 12.196 18.2033Z" fill="#040413" fill-opacity="0.56"/>
    </svg>

    <svg v-else-if="type=='Unsatisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="#98A0A9"/>
    <circle cx="16" cy="16" r="15.75" stroke="#525280" stroke-opacity="0.18" stroke-width="0.5"/>
    <path d="M7.59349 10.1999C7.90879 10.9283 8.7108 11.4216 9.62112 11.3718C10.6044 11.318 11.393 10.6481 11.555 9.7999" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M21.0897 12.7216C20.5597 13.4046 19.5716 13.6908 18.6356 13.3636C17.6063 13.0038 16.9899 12.0243 17.1377 11.0736" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M12.2219 16.4153C11.2569 16.22 10.3017 16.295 9.43276 16.5875C9.11871 16.6933 8.77841 16.5244 8.67268 16.2103C8.56695 15.8963 8.73583 15.556 9.04988 15.4502C10.1134 15.0922 11.2827 15.0009 12.46 15.2392C13.8201 15.5144 14.9988 16.1907 15.8956 17.1196C16.1258 17.358 16.1191 17.7378 15.8807 17.968C15.6423 18.1982 15.2625 18.1915 15.0323 17.9531C14.2989 17.1935 13.3362 16.6408 12.2219 16.4153Z" fill="#040413" fill-opacity="0.56"/>
    </svg>

    <svg v-else-if="type=='Neutral'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="#98A0A9"/>
    <circle cx="16" cy="16" r="15.75" stroke="#525280" stroke-opacity="0.18" stroke-width="0.5"/>
    <circle cx="10.6" cy="14.2" r="1.8" fill="#040413" fill-opacity="0.56"/>
    <circle cx="21" cy="14.2" r="1.8" fill="#040413" fill-opacity="0.56"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M11.6863 19.6998C11.3073 19.6998 11 20.0132 11 20.3998C11 20.7864 11.3073 21.0998 11.6863 21.0998H20.3137C20.6927 21.0998 21 20.7864 21 20.3998C21 20.0132 20.6927 19.6998 20.3137 19.6998H11.6863Z" fill="#040413" fill-opacity="0.56"/>
    </svg>

    <svg v-else-if="type=='Satisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="#98A0A9"/>
    <circle cx="16" cy="16" r="15.75" stroke="#525280" stroke-opacity="0.18" stroke-width="0.5"/>
    <path d="M16.3737 10.0617C16.0781 9.52715 15.472 9.10611 14.7239 8.98555C13.9757 8.865 13.2681 9.07438 12.8195 9.48903" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path d="M25.7199 11.5676C25.4243 11.033 24.8182 10.612 24.07 10.4914C23.3219 10.3709 22.6143 10.5802 22.1657 10.9949" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M13.7804 13.1905C14.0979 13.0955 14.4322 13.2759 14.5272 13.5934C14.9221 14.9131 16.1648 16.0844 17.8735 16.4533C19.5822 16.8221 21.1974 16.2678 22.1016 15.2284C22.3191 14.9784 22.6981 14.9521 22.9481 15.1696C23.1981 15.3871 23.2244 15.766 23.0069 16.016C21.7847 17.421 19.7084 18.077 17.6203 17.6262C15.5322 17.1755 13.9114 15.7214 13.3776 13.9374C13.2826 13.6199 13.4629 13.2855 13.7804 13.1905Z" fill="#040413" fill-opacity="0.56"/>
    </svg>

    <svg v-else-if="type=='Very Satisfied'" width="32" height="32" viewBox="0 0 32 32" fill="none" xmlns="http://www.w3.org/2000/svg">
    <circle cx="16" cy="16" r="16" fill="#98A0A9"/>
    <circle cx="16" cy="16" r="15.75" stroke="#525280" stroke-opacity="0.18" stroke-width="0.5"/>
    <path d="M17.9333 20.6714C21.7012 21.399 25.35 19.0459 26.2779 15.3713C26.3367 15.1388 26.2059 14.9037 25.9827 14.8161C21.7313 13.1481 17.2097 12.2749 12.6429 12.2399C12.4031 12.2381 12.1942 12.4076 12.1621 12.6453C11.6552 16.4012 14.1653 19.9437 17.9333 20.6714Z" fill="#040413" fill-opacity="0.56"/>
    <path d="M13.61 5.44211L17.2535 8.607L12.8515 9.36955" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round" stroke-linejoin="round"/>
    <path d="M27.5624 8.13647L23.0024 9.7171L26.804 12.0639" stroke="#040413" stroke-opacity="0.56" stroke-width="1.6" stroke-linecap="round" stroke-linejoin="round"/>
    <path fill-rule="evenodd" clip-rule="evenodd" d="M23.8651 19.1686C22.2671 20.4779 20.1204 21.0934 17.9334 20.6711C15.7465 20.2487 13.9832 18.8781 12.9877 17.0679C14.5857 15.7586 16.7325 15.1431 18.9194 15.5654C21.1063 15.9878 22.8696 17.3584 23.8651 19.1686Z" fill="#040413" fill-opacity="0.1"/>
    </svg>
  </div>
</template>

<script>
export default {
  props: ['active', 'type']
}
</script>
