<template>
  <svg :width="width" :height="height" viewBox="0 0 200 200" fill="none" xmlns="http://www.w3.org/2000/svg">
  <mask id="mask0" mask-type="alpha" maskUnits="userSpaceOnUse" x="0" y="0" width="200" height="200">
  <rect width="200" height="200" rx="50" fill="#C4C4C4"/>
  </mask>
  <g mask="url(#mask0)">
  <g clip-path="url(#clip0)">
  <path d="M70.7231 161.778C70.3056 161.725 69.8881 161.569 69.575 161.308C68.8444 160.682 68.6878 159.586 69.2097 158.751L89.563 118.879L69.4706 101.761C68.9487 101.448 68.5834 100.874 68.5312 100.196C68.4791 99.5696 68.74 98.9433 69.2097 98.5258L129.226 38.8227C129.957 38.1965 131.105 38.1965 131.835 38.8749C132.566 39.5012 132.722 40.5971 132.201 41.4321L110.438 80.26L131.522 98.578C132.044 98.8911 132.409 99.4652 132.462 100.144C132.514 100.77 132.253 101.396 131.783 101.814L72.1844 161.308C71.7669 161.673 71.245 161.83 70.7231 161.778Z" fill="url(#paint0_linear)"/>
  <path d="M36.2789 103.275C34.7654 101.762 34.7654 99.3088 36.2789 97.7953L60.4941 73.5801L61.5901 74.676C63.9907 77.0767 63.9907 81.043 61.5901 83.4436L44.5246 100.509L61.4335 117.418C63.8342 119.819 63.8342 123.785 61.4335 126.186L60.3376 127.282L36.2789 103.275Z" fill="url(#paint1_linear)"/>
  <path d="M138.515 126.186C136.114 123.785 136.114 119.819 138.515 117.418L155.581 100.353L138.672 83.4436C136.271 81.043 136.271 77.0767 138.672 74.676L139.768 73.5801L163.826 97.6387C165.34 99.1522 165.34 101.605 163.826 103.118L139.611 127.334L138.515 126.186Z" fill="url(#paint2_linear)"/>
  </g>
  </g>
  <defs>
  <linearGradient id="paint0_linear" x1="100.516" y1="38.3594" x2="100.516" y2="161.787" gradientUnits="userSpaceOnUse">
  <stop stop-color="#57A3FF"/>
  <stop offset="1" stop-color="#3C82FB"/>
  </linearGradient>
  <linearGradient id="paint1_linear" x1="49.2672" y1="73.5801" x2="49.2672" y2="127.282" gradientUnits="userSpaceOnUse">
  <stop stop-color="#57A3FF"/>
  <stop offset="1" stop-color="#3C82FB"/>
  </linearGradient>
  <linearGradient id="paint2_linear" x1="150.838" y1="73.5801" x2="150.838" y2="127.334" gradientUnits="userSpaceOnUse">
  <stop stop-color="#57A3FF"/>
  <stop offset="1" stop-color="#3C82FB"/>
  </linearGradient>
  <clipPath id="clip0">
  <rect x="35.1304" y="38.3008" width="129.844" height="123.477" fill="white"/>
  </clipPath>
  </defs>
<animate v-if="animate" id='ani1' attributeName='fill-opacity' attributeType='XML' begin='0s;ani2.end' dur='2s' from='1' to='0.4' fill='freeze'/>
<animate v-if="animate" id='ani2' attributeName='fill-opacity' attributeType='XML' begin='ani1.end' dur='2s' from='0.4' to='1' fill='freeze'/>
  </svg>
</template>

<script>
export default {
  props: ['width', 'height', 'animate'],
  data () {
    return {
    }
  }
}
</script>
