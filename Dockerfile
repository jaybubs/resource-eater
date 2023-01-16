FROM scratch
COPY ./eat /eat
ENTRYPOINT ["/eat" ]
