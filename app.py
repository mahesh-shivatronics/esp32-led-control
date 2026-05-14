import streamlit as st
import requests

ESP32_IP = "http://192.168.0.103"

st.title("ESP32 LED Control")

if st.button("LED ON"):
    requests.get(f"{ESP32_IP}/on")
    st.success("LED ON")

if st.button("LED OFF"):
    requests.get(f"{ESP32_IP}/off")
    st.error("LED OFF")